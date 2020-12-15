pacman -Sc

nano /etc/locale.gen
locale-gen

ln -s /usr/share/zoneinfo/Asia/Taipei /etc/localtime
hwclock --systohc --utc

systemctl enable dhcpcd.service
mkinitcpio -p linux
passwd

pacman -S alsa-utils
pacman -Sc
alsamixer

for var in grub gvim sudo adobe-source-han-sans-tw-fonts adobe-source-han-sans-jp-fonts
do 
  pacman -S $var
  pacman -Sc
done

echo ArchSid >> /etc/hostname
nano /etc/hosts

grub-install /dev/sda
grub-mkconfig -o /boot/grub/grub.cfg

useradd -m -g users -G wheel -s /bin/bash sidney
passwd sidney
visudo

pacman -Syu
rm -R /var/cache/pacman/pkg

for var in make gcc perl virtualbox-guest-modules-arch virtualbox-guest-utils 
do 
  pacman -S $var
  pacman -Sc
done

modprobe -a vboxguest vboxsf vboxvideo
systemctl enable vboxservice.service

for var in xorg-server xorg-server-utils xorg-xinit xorg-twm xorg-clock xterm
do 
  pacman -S $var
  pacman -Sc
done

startx
