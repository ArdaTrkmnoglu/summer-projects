fn main() {
    let num = 7;
    let mut condition = true;

    if num != 0 {
        println!("{num} is a nonzero number.");
    } else {
        println!("{num} is zero.");
    }

    if num % 2 == 0 {
        println!("{num} is divisible with 2.");
    }
    else if num % 3 == 0 {
        println!("{num} is divisible with 3.");
    }
    else if num % 5 == 0 {
        println!("{num} is divisible with 5.");
    }
    else {
        println!("{num} is not divisible with 2, 3, or 5.");
        condition = false;
    }

    let lucky = if condition { 5 } else { 85 };
    println!("{lucky}");
}
