FROM debian:buster-slim

RUN apt-get update -y
RUN apt-get install -y nginx libnginx-mod-http-lua libnginx-mod-http-perl zlib1g lua-zlib gettext-base

# Delete default config
RUN rm -r /etc/nginx/conf.d && rm /etc/nginx/nginx.conf

# Create folder for PID file
RUN mkdir -p /run/nginx

# Add our nginx conf
# COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./decompress.lua /etc/lua/decompress.lua

CMD ["nginx"]
