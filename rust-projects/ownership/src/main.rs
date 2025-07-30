fn main() {
    let male = String::from("Arda");
    let female = String::from("Ayda");

    concatenate(&male, &female);
    let st = format!("{} <3 {}", male, female);
    println!("{st}");

    let mut vector: Vec<i32> = vec![2, 4, 5];
    let num: &mut i32 = &mut vector[0];

    *num += 1;
    println!("First element: {}", *num);

    println!("The vector is: {:?}", vector);
}

fn concatenate(w1: &String, w2: &String) {
    println!("{} and {}", w1, w2);
}
