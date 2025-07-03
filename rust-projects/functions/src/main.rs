fn main() {
    println!("Hello, world!");
    new_func();
    value(5);
    measurement(32, 'C');
}

fn new_func() {
    println!("New function!");
}

fn value(num: i32) {
    println!("The value of x = {num}.");
}

fn measurement(val: i32, unit_label: char) {
    println!("The temperature is {val} {unit_label}.");
}