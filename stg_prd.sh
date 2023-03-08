#!/bin/bash
<<<<<<< HEAD
sudo sheckout prd
sudo git merge stg  
=======
sudo git checkout prd
sudo git merge stg
>>>>>>> dev
sudo git tag `date "+%Y%m%d%H%M%S"` 
sudo git push --tags
sudo git push 
sudo git checkout stg
<<<<<<< HEAD
=======

>>>>>>> dev
