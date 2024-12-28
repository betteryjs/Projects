# 使用官方Python运行时作为父镜像
FROM python:3.6-slim

# 设置工作目录
WORKDIR /app

# 将当前目录内容复制到位于/app中的容器中
COPY . /app

# 安装任何所需的包
RUN pip install --no-cache-dir -r requirements.txt

# 让容器监听5000端口
EXPOSE 5000

# 定义环境变量
ENV NAME World

# 运行gunicorn服务器
CMD ["gunicorn", "-w", "4", "-b", "0.0.0.0:5000", "app:app"]