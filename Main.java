import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of iterations: ");
        int iterations = scanner.nextInt();
        System.out.print("Enter the sleep duration (in milliseconds): ");
        int sleepDuration = scanner.nextInt();

        // Creating and starting threads using MyThread
        MyThread thread1 = new MyThread(iterations, sleepDuration);
        MyThread thread2 = new MyThread(iterations, sleepDuration);
        thread1.start();
        thread2.start();

        // Creating and starting threads using MyRunnable
        MyRunnable myRunnable = new MyRunnable(iterations, sleepDuration);
        Thread thread3 = new Thread(myRunnable);
        Thread thread4 = new Thread(myRunnable);
        thread3.start();
        thread4.start();

        scanner.close();
    }
}
