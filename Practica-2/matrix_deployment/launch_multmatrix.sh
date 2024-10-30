#!/bin/bash

if [[ $1 == "-h" || $1 == "--help" ]]; then
    echo "Script to deploy multmatrix in Kubernetes. '-r' or '--relaunch' to delete previous deployments"
    exit
fi

if [[ $1 == "-r" || $1 == "--relaunch" ]]; then
    kubectl delete service multmatrix-service
    kubectl delete deployment multmatrix
fi

kubectl apply -f mult_matrix.yaml
kubectl apply -f mult_matrix_service.yaml
