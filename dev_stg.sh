<<<<<<< HEAD
<<<<<<< HEAD
#!/bim/bash
=======
#!/bin/bash
>>>>>>> dev
=======
#!/bin/bash
>>>>>>> b3927fb0d7ec11150c8a3a5842294a4218db33c9
sudo git checkout stg
sudo git merge dev
sudo git tag `date "+%Y%m%d%H%M%S"` 
sudo git push --tags
sudo git push 
sudo git checkout dev
