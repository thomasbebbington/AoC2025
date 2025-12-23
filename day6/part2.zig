const std = @import("std");

pub fn main() !void {
    const allocator = std.heap.page_allocator;

    var file = try std.fs.cwd().openFile("input.txt", .{});
    defer file.close();

    const data = try file.readToEndAlloc(allocator, 10 * 1024 * 1024);
    defer allocator.free(data);

    var splitter = std.mem.tokenizeScalar(u8, data, '\n');

    const l1 = splitter.next().?;
    const l2 = splitter.next().?;
    const l3 = splitter.next().?;
    const l4 = splitter.next().?;

    const l5 = splitter.next().?;
    var o5 = std.mem.tokenizeScalar(u8, l5, ' ');
    var w5 = std.mem.tokenizeAny(u8, l5, "+*");

    var indx: u64 = 0;
    var total: u64 = 0;

    while (w5.peek() != null){
        const c5 = o5.next().?;
        const whitespace = w5.next().?;
        var length: u64 = undefined;
        if (w5.peek() == null) {
            length = whitespace.len + 1;
        } else {
            length = whitespace.len;
        }

        const c1 = l1[indx..indx + length];
        const c2 = l2[indx..indx + length];
        const c3 = l3[indx..indx + length];
        const c4 = l4[indx..indx + length];

        indx = indx + length + 1;

        var values: [4]u64 = undefined;
        @memset(&values, 0);
        
        for (0..length) |i| {     
            var p: u64 = 1;
            if(c4[i] != ' '){
                values[i] = values[i] + (c4[i] - 48);
                p = p * 10;
            }
            if(c3[i] != ' '){
                values[i] = values[i] + ((c3[i] - 48) * p);
                p = p * 10;
            }
            if(c2[i] != ' '){
                values[i] = values[i] + ((c2[i] - 48) * p);
                p = p * 10;
            }
            if(c1[i] != ' '){
                values[i] = values[i] + ((c1[i] - 48) * p);
                p = p * 10;
            } 
        }

        var curr: u64 = values[0];
        switch (c5[0]) {
           '+' => {
                for (1..length) |j| {
                    curr = curr + values[j];
                } 
            },
           '*' => {
                for (1..length) |j| {
                    curr = curr * values[j];
                } 
            },
           else => {curr = 0;}, 
        }

        total = total + curr;

    }

    std.debug.print("{d}\n", .{total});
}
