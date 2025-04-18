
let numbers = [2; 4; 4; 6; 8; 10; 4; 6]

let mean lst =
  let sum = List.fold_left (+) 0 lst in
  float_of_int sum /. float_of_int (List.length lst)

let median lst =
  let sorted = List.sort compare lst in
  let len = List.length sorted in
  if len mod 2 = 0 then
    let mid1 = List.nth sorted (len / 2 - 1) in
    let mid2 = List.nth sorted (len / 2) in
    float_of_int (mid1 + mid2) /. 2.0
  else
    float_of_int (List.nth sorted (len / 2))

let mode lst =
  let freq_map =
    List.fold_left
      (fun acc n ->
         let count = try List.assoc n acc with Not_found -> 0 in
         (n, count + 1) :: List.remove_assoc n acc)
      [] lst
  in
  let max_freq = List.fold_left (fun acc (_, c) -> max acc c) 0 freq_map in
  List.fold_left
    (fun acc (n, c) -> if c = max_freq then n :: acc else acc)
    [] freq_map

let () =
  Printf.printf "Numbers: ";
  List.iter (fun n -> Printf.printf "%d " n) numbers;
  Printf.printf "\nMean: %.2f\n" (mean numbers);
  Printf.printf "Median: %.2f\n" (median numbers);
  Printf.printf "Mode: ";
  List.iter (fun n -> Printf.printf "%d " n) (mode numbers);
  print_newline ()
