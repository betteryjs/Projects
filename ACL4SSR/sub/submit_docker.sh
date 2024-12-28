#!/usr/bin/bash


## remove local docker images
sudo docker rmi betteryjs/sub
sudo docker rmi sub
sudo docker rmi cdn-reg.naloong.de/library/sub


## build docker images
sudo docker build -t 'sub' .


# push to docker hub
sudo docker login
sudo docker tag sub betteryjs/sub
sudo docker push betteryjs/sub

## sava to local .tar
#sudo docker save sub > sub.tar



# push to cdn-reg.naloong.de
sudo docker logout
sudo docker login cdn-reg.naloong.de
sudo docker tag sub cdn-reg.naloong.de/library/sub
sudo docker push  cdn-reg.naloong.de/library/sub



## docker load from local
# docker load < sub.tar
# docker tag sub betteryjs/sub
# sudo docker run -d -p 5000:5000  --restart unless-stopped --name sub betteryjs/sub


## run docker
# docker-compose up -d