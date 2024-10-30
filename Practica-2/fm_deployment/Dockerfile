FROM ubuntu:latest

RUN apt-get update && apt-get install -y software-properties-common

# Copy the executable to the image
COPY ./fileServer /app/fileServer

# Set the working directory
WORKDIR /app

RUN mkdir ./dirprueba

# Make the executable executable
RUN chmod +x /app/fileServer

RUN touch fileServerLogs.txt

# Specify the command to run when the container starts
CMD ["/app/fileServer", ">", "/app/fileServerLogs.txt"]
