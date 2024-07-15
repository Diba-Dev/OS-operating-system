public class MyRunnable implements Runnable {
    private int iterations;
    private int sleepDuration;

    public MyRunnable(int iterations, int sleepDuration) {
        this.iterations = iterations;
        this.sleepDuration = sleepDuration;
    }

    @Override
    public void run() {
        for (int i = 1; i <= iterations; i++) {
            System.out.println(Thread.currentThread().getName() + ": " + i);
            try {
                Thread.sleep(sleepDuration);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}
