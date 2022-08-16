sudo pacman -Syu ogre boost-libs boost freeimage freetype2 libxaw libxrandr mesa nvidia-cg-toolkit ois zziplib gcc
sudo pacman -S wget
sudo pacman -S unzip
sudo pacman -S pkg-confi cmake
sudo pacman -S qtcreator
mkdir ogre && cd ogre
wget http://www.ogre3d.org/tikiwiki/tiki-download_wiki_attachment.php?attId=186&download=y
unzip *
mv clean_ogre_cmake_project ogre3d && cd ogre3d
cmake .
cp /opt/OGRE/samples/plugins.cfg ./dist/bin
make && make install
qtcreator CMakeList.txt
