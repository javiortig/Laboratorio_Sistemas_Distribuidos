
sudo apt purge docker*
sudo rm -r /etc/docker/
sudo rm -r /etc/apt/sources.list.d/docker.list 
sudo rm -r /etc/apt/sources.list.d/kubernetes.list
sudo apt purge containerd
sudo rm -r /etc/containerd
sleep 10
sudo apt-get update && sudo apt-get install -y apt-transport-https gnupg2 curl

curl -s https://packages.cloud.google.com/apt/doc/apt-key.gpg | sudo apt-key add -
echo "deb https://apt.kubernetes.io kubernetes-xenial main" | sudo tee -a /etc/apt/sources.list.d/kubernetes.list

#apagar la swap
sudo sed -i '/ swap / s/^\(.*\)$/#\1/g' /etc/fstab
sudo swapoff -a

sudo apt-get update
sudo apt-get install -y kubectl kubeadm kubernetes-cni


sudo apt-get install -y containerd
sudo apt-get install -y docker.io
sudo apt-get install -y conntrack
 
sudo modprobe overlay
sudo modprobe br_netfilter
 
sudo tee /etc/sysctl.d/kubernetes.conf<<EOF
net.bridge.bridge-nf-call-ip6tables = 1
net.bridge.bridge-nf-call-iptables = 1
net.ipv4.ip_forward = 1
EOF
 
 
sudo tee /etc/docker/daemon.json <<EOF
{
  "exec-opts": ["native.cgroupdriver=systemd"],
  "log-driver": "json-file",
  "log-opts": {
    "max-size": "100m"
  },
  "storage-driver": "overlay2"
}
EOF
 
sudo systemctl daemon-reload 
  sudo systemctl restart docker
sudo systemctl enable docker.service
sudo systemctl enable kubelet.service
sleep 5


sudo kubeadm init
mkdir -p $HOME/.kube
sudo cp -i /etc/kubernetes/admin.conf $HOME/.kube/config
sudo chown $(id -u):$(id -g) $HOME/.kube/config
sudo curl -L git.io/weave -o /usr/local/bin/weave
sudo chmod a+x /usr/local/bin/weave
#kubectl apply -f "https://cloud.weave.works/k8s/net?k8s-version=$(kubectl version | base64 | tr -d '\n')"
kubectl apply -f https://github.com/weaveworks/weave/releases/download/v2.8.1/weave-daemonset-k8s.yaml
sleep 5
kubectl get nodes
kubectl taint nodes --all node-role.kubernetes.io/control-plane- node-role.kubernetes.io/master-
sudo systemctl start docker 
#sudo kubeadm reset #<-- Este comando se ejecuta sólo en los esclavos
#kubeadm join 172.31.75.106:6443 --token r9yduf.84owjw44yym9ubtt \
#        --discovery-token-ca-cert-hash sha256:2fe7ad6f7ea98c7804aa155564c01faa276344406d641fd73dbbc5cee4fb6283
# El comando anterior se obtiene del master la primera vez que se instala