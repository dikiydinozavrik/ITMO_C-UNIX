#!/bim/bash
sudo git checkout stg
sudo git merge dev
sudo git tag `date "+%Y%m%d%H%M%S"` 
sudo git push --tags
sudo git push 
sudo git checkout dev
