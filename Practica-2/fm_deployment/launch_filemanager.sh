#!/bin/bash

if [[ $1 == "-h" || $1 == "--help" ]]; then
    echo "Script to deploy filemanager in Kubernetes. '-r' or '--relaunch' to delete previous deployments"
    exit
fi

if [[ $1 == "-r" || $1 == "--relaunch" ]]; then
    kubectl delete service filemanager-service
    kubectl delete deployment filemanager
fi

kubectl apply -f file_manager.yaml
kubectl apply -f file_manager_service.yaml
