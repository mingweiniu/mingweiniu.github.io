
diff -u after.txt before.txt > out.txt

gitk --follow target_file.txt

git reset --soft HEAD^1

git stash
git stash apply
git reset --mixed

git fetch --all

# remove from github
git reset HEAD */build/*
