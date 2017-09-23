#!/bin/bash
echo "setup all model!!!"

echo "***************111zbcar_admin_server***********************************************"
sleep 3
cd /data/zbcar_admin_server && ./zbcar_admin_server -s stop
sleep 3
cd /data/zbcar_admin_server && ./zbcar_admin_server -f cfg.conf

echo "****************222zbcar_agent******************************************************"
sleep 3
cd /data/zbcar_agent_server && ./zbcar_agent -s stop
sleep 3
cd /data/zbcar_agent_server && ./zbcar_agent -f zbcar_agent.cfg

echo "****************333zbcar_alarm_server***********************************************"
sleep 3
cd /data/zbcar_alarm_server && ./zbcar_alarm_server -s stop
sleep 3
cd /data/zbcar_alarm_server && ./zbcar_alarm_server -f cfg.conf

echo "***************444zbcar_business***************************************************"
sleep 3
cd /data/zbcar_business_server && ./zbcar_business -s stop
sleep 3
cd /data/zbcar_business_server && ./zbcar_business -f cfg.conf

echo "***************555zbcar_car*****************************************************"
sleep 3
cd /data/zbcar_carinfo && ./zbcar_car -s stop 
sleep 3
cd /data/zbcar_carinfo && ./zbcar_car -f cfg.conf

echo "**************666zbcar_dbtofile**************************************************"
sleep 3
cd /data/zbcar_dbtofile && ./zbcar_dbtofile -s stop 
sleep 3
cd /data/zbcar_dbtofile && ./zbcar_dbtofile -f cfg.conf

echo "***************777zbcar_dev_server************************************************"
sleep 3
cd /data/zbcar_dev_server && ./zbcar_dev_server -s stop 
sleep 3
cd /data/zbcar_dev_server && ./zbcar_dev_server -f cfg.conf

echo "****************888zbcar_gps_server***********************************************"
sleep 3
cd /data/zbcar_gps_server && ./zbcar_gps_server -s stop 
sleep 3
cd /data/zbcar_gps_server && ./zbcar_gps_server -f cfg.conf

echo "****************999zbcar_locationserver********************************************"
sleep 3
cd /data/zbcar_location_server && ./zbcar_locationserver -s stop 
sleep 3
cd /data/zbcar_location_server && ./zbcar_locationserver -f cfg.conf

echo "*****************101010zbcar_login_server*********************************************"
sleep 3
cd /data/zbcar_login && ./zbcar_login_server -s stop 
sleep 3
cd /data/zbcar_login && ./zbcar_login_server -f cfg.conf

echo "****************111111zbcar_manager_server********************************************"
sleep 3
cd /data/zbcar_manager && ./zbcar_manager_server -s stop 
sleep 3
cd /data/zbcar_manager && ./zbcar_manager_server -f cfg.conf

echo "****************121212zbcar_manager_server********************************************"
sleep 3
cd /data/zbcar_manager && ./zbcar_manager_server -s stop 
sleep 3
cd /data/zbcar_manager && ./zbcar_manager_server -f cfg.conf

echo "***************131313zbcar_push*******************************************************"
sleep 3
cd /data/zbcar_push && ./zbcar_push -s stop
sleep 3
cd /data/zbcar_push && ./zbcar_push -f cfg.conf

echo "****************141414zbcar_recycle***************************************************"
sleep 3
cd /data/zbcar_recycle && ./zbcar_recycle -s stop 
sleep 3
cd /data/zbcar_recycle && ./zbcar_recycle -f cfg.conf

echo "*****************151515send_mail_server*********************************************"
sleep 3
cd /data/zbcar_send_mail_server && ./send_mail_server -s stop
sleep 3
cd /data/zbcar_send_mail_server && ./send_mail_server -f cfg.conf


 
