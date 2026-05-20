void perform_task() {
    static int call_count = 0; // A temporary worker with a permanent station
    int temp_var = 0; // Real casual workers, hired daily
    call_count++;
    temp_var++;
    printf("Permanent tracker: %d, Temporary note: %d\n", call_count, temp_var);
}
// First call: Permanent tracker: 1, Temporary note: 1
// Second call: Permanent tracker: 2, Temporary note: 1

