use std::{env::args, process::exit, vec};

fn main() {
    match args().nth(1) {
        None => {
            eprint!("usage: <program> <input>");
            exit(1);
        }
        Some(arg) => {
            let input: Vec<char> = arg.chars().collect();
            vulnerable_code(&input);
        }
    }
}

// NOTE: Not actually vulnerable
fn vulnerable_code(input_str: &[char]) {
    let mut small_buffer = [0 as char; 32];
    strcpy(&mut small_buffer, input_str);
    str_to_lowercase(&mut small_buffer);
    println!(
        "The string '{}' in lowercase is: '{}'",
        slice2str(input_str),
        slice2str(&small_buffer)
    );
}

fn str_to_lowercase(string: &mut [char]) {
    let mut temp = vec![0 as char; string.len()];
    temp.clone_from_slice(string);
    for (i, character) in temp.iter().enumerate() {
        string[i] = character.to_ascii_lowercase();
    }
}

// NOTE: Rust has no equivalent strcpy()
fn strcpy(dest: &mut [char], src: &[char]) {
    for (i, character) in src.iter().enumerate() {
        dest[i] = *character;
    }
}

// ---------- Helper -------------
fn slice2str(slice: &[char]) -> String {
    slice.iter().collect()
}

