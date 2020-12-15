sudo pacman -Syu --needed base-devel git
git clone https://aur.archlinux.org/yaourt.git 
git clone https://aur.archlinux.org/package-query.git
cd yaourt
makepkg -sri
cd ../package-query
makepkg -sri
yaourt -Syu
