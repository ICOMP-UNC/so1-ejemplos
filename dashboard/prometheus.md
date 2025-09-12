you can use apt-get to install Prometheus on Ubuntu. Here are the steps:

    Update your package list:

```bash
    sudo apt-get update
```
    Install Prometheus:
```bash
    sudo apt-get install prometheus -y
```
This will install Prometheus along with its default configuration files. You can then start Prometheus using:
```bash
sudo systemctl start prometheus
```
To ensure Prometheus starts on boot, enable the service:
``` bash
sudo systemctl enable prometheus
```

Configuration

    The default configuration file is located at /etc/prometheus/prometheus.yml. You can edit this file to customize your Prometheus setup.

Verify Installation

    Open your browser and go to http://localhost:9090. You should see the Prometheus UI.


Stop prometheus, then launch it with the config file:
```
sudo systemctl stop prometheus
```
```
prometheus --config.file=./prometheus.yml --storage.tsdb.path=./prometheus_data
```

prometheus --config.file=./prometheus.yml --storage.tsdb.path=./prometheus_data ``


```bash
➜  solucion sudo lsof -i -P -n | grep LISTEN
[sudo] password for pablo:          
prometheu   515      prometheus    3u  IPv6  25947      0t0  TCP *:9100 (LISTEN)
prometheu   517      prometheus    3u  IPv6  29365      0t0  TCP *:9090 (LISTEN)
cupsd       677            root    6u  IPv6  29465      0t0  TCP [::1]:631 (LISTEN)
cupsd       677            root    7u  IPv4  29466      0t0  TCP 127.0.0.1:631 (LISTEN)
grafana     966         grafana   13u  IPv6  34214      0t0  TCP *:3000 (LISTEN)
systemd-r  4601 systemd-resolve   13u  IPv4  57824      0t0  TCP 127.0.0.53:53 (LISTEN)
metrics   31688           pablo    4u  IPv4 147996      0t0  TCP *:8000 (LISTEN)
```

```
You can check the status of the targets defined in the prometheus.yml in Status/Target:

http://localhost:9090/targets

```