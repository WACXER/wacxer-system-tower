//Exception and thread
//In Java every thread has its own seperate 
//call invocations done during the thread's l;ifetime
//when an exception is raised, that thread's call stack becomes 
//a vital part of diagnostiv history;
//it shows the sequence of method inocation that 
//led to the exception 


//In the scenario below 
//the database operation failed 
//which propagate back up the call stgack up 
//The main thread starts calling ProcessOrder 
//which calls validateOrderDetails, which calls 
//checkInventory, which calls UpdateDatabase
//which then throws the exception  

import java.sql.SQLException;
public class CallStackDemo {
    public static void main(String[] args) throws InterruptedException {
        Thread thread = new Thread(CallStackDemo::processOrder);
        thread.setName("mcj-thread");
        thread.start();
        thread.join();
    }
    static void processOrder() {
        validateOrderDetails();
    }
    static void validateOrderDetails() {
        checkInventory();
    }
    static void checkInventory() {
        updateDatabase();
    }
    static void updateDatabase() {
        try {
            throw new SQLException("Database connection error");
        } catch (SQLException e) {
            throw new InventoryUpdateException("Database Error: " +
                "Unable to update inventory", e);
        }
    }
}
class InventoryUpdateException extends RuntimeException {
    public InventoryUpdateException(String message, Throwable cause) {
        super(message, cause);
    }
}