mkswap /dev/sda3
swapon /dev/sda3
mkfs.ext4 /dev/sda2
mkfs.ext4 /dev/sda4

mount /dev/sda4 /mnt
cp install.txt /mnt
cd /mnt
mkdir boot
mount  /dev/sda2 boot

nano /etc/pacman.d/mirrorlist
pacstrap . base
genfstab -p . >> ./etc/fstab
arch-chroot .
nano /etc/pacman.d/mirrorlist
