use std::{env::args_os, process::exit};

fn main() {
    match args_os().nth(1) {
        None => {
            eprint!("usage: <program> <input>");
            exit(1);
        }
        Some(arg) => {
            let mut input: Vec<u8> = arg.into_encoded_bytes();
            lowercase_print(&mut input);
        }
    }
}

fn lowercase_print(input_str: &mut [u8]) {
    let mut unmodified = [0; 32];
    strcpy(&mut unmodified, input_str);
    str_to_lowercase(input_str);
    println!(
        "The string '{}' in lowercase is: '{}'",
        slice2str(&unmodified),
        slice2str(input_str)
    );
}

// NOTE: Rust has no equivalent strcpy()
fn strcpy(dest: &mut [u8], src: &[u8]) {
    for (i, character) in src.iter().enumerate() {
        dest[i] = *character;
    }
}

fn str_to_lowercase(string: &mut [u8]) {
    let mut temp = vec![0; string.len()];
    temp.clone_from_slice(string);
    for (i, character) in temp.iter().enumerate() {
        string[i] = character.to_ascii_lowercase();
    }
}

// ---------- Helper -------------
fn slice2str(slice: &[u8]) -> String {
    slice.iter().map(|code| *code as char).collect()
}
