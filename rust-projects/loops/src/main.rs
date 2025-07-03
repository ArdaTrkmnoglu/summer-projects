fn main() {
    let mut x = 0;
    loop {
        x += 1;
        println!("{x}");
        if x == 15 {
            break;
        }
    }

    let mut a = 0;
    let mut b = 10;
    'outer: loop {
        loop {
            print!("a = {a}, ");
            println!("b = {b}");
            a += 1;
            b -= 1;
            if b < 0 {
                break 'outer;
            }
        }
    }

    let arr = [1, 2, 3, 4, 5];

    // let mut index = 0;
    // print!("arr = [ ");
    // while index < 5 {
    //     print!("{} ", arr[index]);
    //     index += 1;
    // }
    // println!("]");

    print!("arr = [ ");
    for element in arr {
        print!("{element} ");
    }
    println!("]");

    for i in 0..5 {
        println!("{}", arr[i]);
    }
    
}
