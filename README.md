# Network Security Monitoring Dashboard

## Overview

The **Network Security Monitoring Dashboard** project is designed to visualize network traffic, alerts, and security events using the ELK Stack (Elasticsearch, Logstash, Kibana). This application collects network traffic data using a C++ backend and sends it to Elasticsearch for storage and analysis.

## Key Features

- **Real-Time Traffic Monitoring**: Collects and aggregates network traffic data at regular intervals.
- **Data Visualization**: Leverages Kibana to visualize network traffic and security events in a user-friendly dashboard.
- **Customizable Configuration**: Use a JSON configuration file to easily adjust settings such as Elasticsearch host and port.

## Technologies Used

- **C++**: The programming language used for developing the network monitoring application.
- **ELK Stack**: Utilizes Elasticsearch for data storage, Logstash for data processing, and Kibana for visualization.
- **Docker**: Simplifies the deployment of the application and the ELK Stack.
