echo "kern.vty=vt" >> /boot/loader.conf

echo "kld_list=\"i915kms\"" >> /etc/rc.conf

echo "exec /usr/local/bin/startxfce4 --with-ck-launch" > ~/.xinitrc

startx
