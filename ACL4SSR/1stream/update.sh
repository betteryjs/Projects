#!/usr/bin/bash

cd ..
git add .
git commit -m "fix"
git push origin master

cd 1stream
/home/yjs/.conda/envs/ddospy37/bin/python parse.py

cd ..
git add .
git commit -m "fix"
git push origin master

/home/yjs/.conda/envs/ddospy37/bin/python savesrs.py



cd ..
git add .
git commit -m "fix"
git push origin master
