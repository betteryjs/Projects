#! /usr/local/bin/zsh


: 要备份的文件路径
backup_base_dir="/mnt/Pool/NAS/"
: rclone 实时日志
log_path="/root/sh/bachup_rclone.log"
: 记录传输完成时间日志
backup_success_log_path="/root/sh/bachup_rclone_success.log"
: 线程数
transfers=8




echo ""> ${backup_success_log_path}
echo ""> ${log_path}
bachup_remote_dir="alist:/aliyun-driver/"


rclone_cmd1="rclone mkdir"
rclone_cmd2="rclone sync"
rclone_flag="-v -P  --transfers="${transfers}" --ignore-errors > "${log_path}" 2>&1"


cd ${backup_base_dir}
lsdir=`ls -d */`



for element (${(f)${lsdir}}) {
        res1=${rclone_cmd1}" "${bachup_remote_dir}${element}

	res2=${rclone_cmd2}" "${backup_base_dir}${element}" "${bachup_remote_dir}${element}" "${rclone_flag}
        echo "-------------------------------------------------------------------------------------------" >> ${backup_success_log_path}
        echo "-------------------------------------------------------------------------------------------" >> ${backup_success_log_path}
        echo "start data is " `date`>>  ${backup_success_log_path}
        echo ${res1} >> ${backup_success_log_path}
        echo ${res2} >> ${backup_success_log_path}
        eval ${res1}
	eval ${res2}
	echo "end data is " `date`>>  ${backup_success_log_path}
        echo "-------------------------------------------------------------------------------------------" >> ${backup_success_log_path}
        echo "-------------------------------------------------------------------------------------------" >> ${backup_success_log_path}

}

