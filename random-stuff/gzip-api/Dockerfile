FROM python:3.8.2

WORKDIR /app
COPY echo-server.py /app/server.py

RUN pip install sanic
CMD ["python", "server.py"]
