FROM ubuntu:latest

RUN apt-get update && apt-get install -y software-properties-common

# Copy the executable to the image
COPY ./mainServer /app/mainServer

COPY ./resultado.txt /app/resultado.txt

COPY ./resultado2.txt /app/resultado2.txt

# Set the working directory
WORKDIR /app

# Make the executable executable
RUN chmod +x /app/mainServer

# Specify the command to run when the container starts
CMD ["/app/mainServer", ">", "/app/multMatrixLogs.txt"]
