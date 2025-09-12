A **gauge** is a type of metric used in monitoring systems like Prometheus that represents a value that can go up and down over time. It is typically used for metrics that can fluctuate, such as CPU usage, memory consumption, or temperature.

### Characteristics of a Gauge:
- **Variable in both directions**: Unlike counters, which only increase, a gauge can both increase and decrease.
- **Snapshot of a value**: It represents the current state of a particular measurement at a given time.
- **Common use cases**:
  - CPU or memory usage
  - Disk space used
  - Temperature readings
  - Concurrent requests

### In Prometheus:
In Prometheus, a gauge is a metric type that allows you to track these variable values. The `prom_gauge_set()` function is used to update the gauge with the current value of the metric.

For example, in your program:

```c
prom_gauge_t *cpu_usage;
prom_gauge_set(cpu_usage, usage, NULL);
```

- `cpu_usage` is the gauge that represents the current CPU usage.
- `prom_gauge_set()` updates the gauge with the current CPU usage (`usage`), which can go up or down depending on system activity.

### Difference from Other Metrics:
- **Counter**: Only increases over time (e.g., number of requests).
- **Gauge**: Can increase and decrease (e.g., memory or CPU usage).

In your case, a gauge is ideal for CPU usage because the CPU utilization can rise and fall depending on system load.