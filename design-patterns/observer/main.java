import java.util.ArrayList;
import java.util.List;

interface Observer {
    String getName();
    void notify(String event);
    void register(Observable obj);
    void unregister(Observable obj);
}

interface Observable {
    void notify(Observer obj, String event);
}

class TheObserver implements Observer {
    private List<Observable> observables;
    private String name;

    public TheObserver(String name) {
        this.name = name;
        this.observables = new ArrayList<Observable>();
    }

    public String getName() {
        return this.name;
    }

    public void register(Observable obj) {
        this.observables.add(obj);
    }

    public void unregister(Observable obj) {
        this.observables.remove(obj);
    }

    public void notify(String event) {
        for (Observable o: this.observables) {
            o.notify(this, event);
        }
    }
}

class TheObservable implements Observable {
    private String name;

    public TheObservable(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public void notify(Observer obj, String event) {
        System.out.format(
            "[%s] %s notified event: %s\n",
            this.getName(),
            obj.getName(),
            event
        );
    }
}

class Main {
    public static void main(String[] args) {
        Observer observer = new TheObserver("The Big Observer");
        for (int i = 0; i < 4; i++) {
            observer.register(new TheObservable("The Observable #" + i));
        }

        Observable someObservable = new TheObservable("The Special Observable");
        observer.register(someObservable);

        observer.notify("This is a first event");

        observer.unregister(someObservable);
        observer.notify("This is a second event");
    }
}
