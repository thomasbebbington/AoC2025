use std::error::Error;
use std::cmp::min;
use std::cmp::max;

struct Range(i64, i64);

fn main() -> Result<(), Box<dyn Error>> {
    let input: String = std::fs::read_to_string("input.txt")?;

    let i = input.split('\n');

    let mut ranges: Vec<Range> = Vec::new();

    for line in i {
        if line.contains('-'){
            let r: Vec<&str> = line.split('-').collect::<Vec<_>>();
            ranges.push(Range(r[0].parse::<i64>()?,r[1].parse::<i64>()?));
        }
    }

    let mut goodranges: Vec<Range> = Vec::new();

    while !ranges.is_empty() {
        let mut noconf = true;
        let r: Range = ranges.pop().expect("Some weird shit has happened");

        let iter = ranges.iter_mut();
        for ro in iter {
            if !((r.1 < ro.0) || (r.0 > ro.1)) {
                 noconf = false;
                 let nr = Range(min(r.0, ro.0), max(r.1, ro.1));
                 *ro = nr;
                 break;
            }  
        }
        if noconf {
            goodranges.push(r);
        }
    }

    let mut total: i64 = 0;

    for x in goodranges {
        total += x.1 - x.0 + 1
    }
    
    println!("{}", total);

    Ok(())
}
