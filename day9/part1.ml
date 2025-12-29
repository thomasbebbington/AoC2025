let f = "input.txt"

let rect (vx, vy) (ux, uy) = ((abs (vx - ux)) + 1) * ((abs (vy - uy)) + 1)

let list_to_pair = function
        | [a; b] -> (a,b)
        | _ -> invalid_arg "Not a list of 2"

let getinput ic = 
        let rec loop acc = 
                match input_line ic with
                        | line ->
                                let pair = 
                                        list_to_pair (List.map int_of_string (String.split_on_char ',' line))
                                in loop (pair :: acc)
                        | exception End_of_file ->
                                acc
        in loop []

let maxarea v ls = 
        List.fold_left max 0 (List.map (rect v) ls)

let rec areas list = 
        match list with
                | [x] -> []
                | (v::ls) -> maxarea v ls :: areas ls
                | [] -> []

let () = 
        let rectareas = areas (getinput (open_in f)) in
        Printf.printf "%d\n" (List.fold_left max 0 rectareas)
