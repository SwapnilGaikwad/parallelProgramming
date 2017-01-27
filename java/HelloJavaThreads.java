
public class HelloJavaThreads {

	private static final int THREAD_COUNT = 4;
	private Thread threadList[];
	
	public void demo(){
		threadList = new Thread[THREAD_COUNT];
		for(int i = 0; i < THREAD_COUNT; i++) {
			threadList[i] = new Thread( new ThreadImpl(i));
			threadList[i].start();
		}
		waitForAllThreads();
	}

	private void waitForAllThreads() {
		for(int i = 0; i < THREAD_COUNT; i++) {
			try {
				threadList[i].join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

	public static void main(String[] args) {

		new HelloJavaThreads().demo();
	}
}

class ThreadImpl implements Runnable {

	private int threadId;

	public ThreadImpl(int threadId) {
		this.threadId = threadId;
	}

	@Override
	public void run() {
		System.out.println("Hello From Thread " + threadId);
	}
}
