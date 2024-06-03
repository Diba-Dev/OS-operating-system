public class MyThread extends Thread {
    private int iterations;
    private int sleepDuration;

    public MyThread(int iterations, int sleepDuration) {
        this.iterations = iterations;
        this.sleepDuration = sleepDuration;
    }

    @Override
    public void run() {
        for (int i = 1; i <= iterations; i++) {
            System.out.println(getName() + ": " + i);
            try {
                Thread.sleep(sleepDuration);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}
