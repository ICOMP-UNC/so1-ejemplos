## Install Grafana

Follow steps at: https://grafana.com/docs/grafana/latest/setup-grafana/installation/debian/


```bash
sudo systemctl start grafana-server
sudo systemctl enable grafana-server
```

Open Grafana in your browser by navigating to http://localhost:3000. 

*The default login credentials are: admin/admin*

Step 4: Configure Prometheus to Scrape the Metrics

    Open the Prometheus configuration file (prometheus.yml) and add the following job to scrape the CPU usage metrics:


### Step 4: Configure Prometheus to Scrape the Metrics

Restart prometheus

```
./prometheus --config.file=prometheus.yml
```

### Step 5: Set Up Grafana Dashboard

    Log in to Grafana (http://localhost:3000).


    Add Prometheus as a Data Source:
        Click on the “Configuration” (cogwheel icon) in the sidebar.
        Select “Data Sources”.
        Click on “Add data source”.
        Select “Prometheus” from the list of data source types.


    Create a dashboard:
        Click on the “+” icon in the sidebar and select “Dashboard”.
        Click “Add new panel”.
        In the query editor, select your Prometheus data source.
        Enter a Prometheus query to fetch the metrics you want to visualize (e.g., cpu_usage).


## Reset user 'admin' password

```
sudo grafana-cli admin reset-admin-password <newpass>
sudo systemctl restart grafana-server
sudo systemctl status grafana-server
```

Then, log in:

```
usr: admin
pass: <newpass>
```