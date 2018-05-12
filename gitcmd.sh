#install git at local
git config --global user.name "aimery.wei"
git config --global user.email "aimery.wei@gmail.com"
cat .gitconfig |head -3
mkdir gitRepository
cd gitRepository
git init
touch readme.txt
vim readme.txt
cat readme.txt
git add readme.txt
git commit -m "This is the first commit which is a readme.txt"
git branch
git log
git status

git diff readme.txt
git log --pretty=oneline

git reset --hard HEAD^
git reset --hard f79d1e898bcd2
#check history commit id
git reflog

git diff HEAD -- readme.txt
#give up work area modification   (before add)
git checkout -- readme.txt
#give up added modification  (after add before commit)
git reset HEAD readme.txt

touch testrm.txt
git status
git add testrm.txt
git commit -m "add testrm.txt"
rm  testrm.txt
git rm testrm.txt

#apply a github account then:
cd ~
#check .ssh if not existed
ssh-keygen -t rsa -C "aimery.wei@gmail.com"
#check .ssh if existed
cd .ssh
cat id_rsa.pub
#copy the .pub context
#create a repository on github with the same name as local repository
#paste the copied public ssh key to gitHub's ssh key
git remote add origin git@github.com:Aimery1990/gitRepository.git
git push -u origin master
#modifiy local file and commit and push to github repository
git push origin master
