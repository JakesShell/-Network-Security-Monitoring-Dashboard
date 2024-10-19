#ifndef TRAFFIC_MONITOR_H
#define TRAFFIC_MONITOR_H

#include <string>
#include <cpprest/http_client.h> // Include the C++ REST SDK
#include <cpprest/json.h>

class TrafficMonitor {
public:
    TrafficMonitor();
    void startMonitoring();
private:
    void sendDataToElasticsearch(const std::string &data);
    std::string collectNetworkTraffic();
};

#endif // TRAFFIC_MONITOR_H
