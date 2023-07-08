class ZeroEvenOdd {
    private int n;
    private int currentNumberToBePrinted;
    private int currentNumber;
    
    public ZeroEvenOdd(int n) {
        this.n = n;
        this.currentNumber = 1;
        this.currentNumberToBePrinted = 0;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        while (currentNumber <= n) {
            synchronized (this) {
                while (currentNumberToBePrinted != 0) {
                    wait();
                }

                if (currentNumber <= n) {
                    printNumber.accept(0);
                }
                currentNumberToBePrinted = currentNumber;   
                
                
                notifyAll();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        while (currentNumber <= n) {
            synchronized (this) {
                while (currentNumberToBePrinted == 0 || currentNumberToBePrinted%2 != 0) {
                    wait();
                }

                if (currentNumberToBePrinted <= n) {
                    printNumber.accept(currentNumberToBePrinted);
                }
                this.currentNumber += 1;
                currentNumberToBePrinted = 0;
                

                notifyAll();
            }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        while (currentNumber <= n) {
            synchronized (this) {
                while (currentNumberToBePrinted == 0 || currentNumberToBePrinted %2 == 0) {
                    wait();
                }


                if (currentNumberToBePrinted <= n) {
                    printNumber.accept(currentNumberToBePrinted);
                }
                this.currentNumber += 1;
                currentNumberToBePrinted = 0;
                

                notifyAll();
            }
        }
    }
}