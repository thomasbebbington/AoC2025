use std::error::Error;
use std::collections::HashMap;

#[derive(Debug)]
struct Range(i64, i64);

fn main() -> Result<(), Box<dyn Error>> {
    let input: String = std::fs::read_to_string("input.txt")?;

    let i = input.split('\n');

    let mut ranges: Vec<Range> = Vec::new();

    let mut ids: Vec<i64> = Vec::new();

    for line in i {
        if line.contains('-'){
            let r: Vec<&str> = line.split('-').collect::<Vec<_>>();
            ranges.push(Range(r[0].parse::<i64>()?,r[1].parse::<i64>()?));
        } else {
            if !line.is_empty() {
                ids.push(line.parse::<i64>()?);
            }
        }
    }

    let mut map: HashMap<i64, i64> = HashMap::new();

    for x in ranges {
        for y in &ids {
            if x.0 <= *y && x.1 >= *y {
                map.entry(*y).and_modify(|count| *count += 1).or_insert(1);
            }
        }
    }

    let mut count: i64 = 0;

    for (_, c) in map {
        if c > 0 {
            count += 1;
        }
    }

    println!("{}", count);

    Ok(())
}
