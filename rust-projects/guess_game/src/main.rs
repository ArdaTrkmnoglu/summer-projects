use std::{cmp::Ordering, io};
use rand::Rng;

fn main() {
    let secret_number = rand::thread_rng().gen_range(1..=50);

    loop {
        println!("Guess the number: ");

        let mut guess = String::new();
        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read the line");

        let guess:u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Please enter a number!");
                continue;
            }
        };

        println!("You guessed: {guess}");

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win!");
                println!("The secret number is: {secret_number}");
                break;
            }
        }
    }   
}
