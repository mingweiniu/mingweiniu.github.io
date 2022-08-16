sudo pacman -S lxde 
rm -R /var/cache/pacman/pkg
cp ./.xinitrc ~/
rm ~/.bash_profile
cp ./.bash_profile ~/
sudo pacman -S ttf-liberation 
rm -R /var/cache/pacman/pkg
