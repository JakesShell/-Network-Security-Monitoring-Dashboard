#include "TrafficMonitor.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace web; // Commonly used C++ REST SDK namespace
using namespace web::http;

TrafficMonitor::TrafficMonitor() {
    // Constructor implementation
}

std::string TrafficMonitor::collectNetworkTraffic() {
    // Simulated data collection (replace with actual traffic monitoring)
    return R"({"source": "192.168.1.1", "destination": "192.168.1.2", "protocol": "TCP", "bytes": 1024})";
}

void TrafficMonitor::sendDataToElasticsearch(const std::string &data) {
    http_client client(U("http://localhost:9200/network-traffic/_doc"));
    json::value jsonData = json::value::parse(data);

    client.request(methods::POST, U(""), jsonData.serialize(), U("application/json"))
        .then([](http_response response) {
            if (response.status_code() == status_codes::OK) {
                std::cout << "Data sent successfully!" << std::endl;
            } else {
                std::cout << "Error sending data: " << response.status_code() << std::endl;
            }
        }).wait();
}

void TrafficMonitor::startMonitoring() {
    while (true) {
        std::string trafficData = collectNetworkTraffic();
        sendDataToElasticsearch(trafficData);
        std::this_thread::sleep_for(std::chrono::seconds(5)); // Collect every 5 seconds
    }
}
