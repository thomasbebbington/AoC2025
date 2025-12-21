const std = @import("std");

pub fn main() !void {
    const allocator = std.heap.page_allocator;

    var file = try std.fs.cwd().openFile("input.txt", .{});
    defer file.close();

    const data = try file.readToEndAlloc(allocator, 10 * 1024 * 1024);
    defer allocator.free(data);

    var splitter = std.mem.tokenizeAny(u8, data, "\n");

    const l1 = splitter.next().?;
    var s1 = std.mem.tokenizeAny(u8, l1, " ");

    const l2 = splitter.next().?;
    var s2 = std.mem.tokenizeAny(u8, l2, " ");

    const l3 = splitter.next().?;
    var s3 = std.mem.tokenizeAny(u8, l3, " ");

    const l4 = splitter.next().?;
    var s4 = std.mem.tokenizeAny(u8, l4, " ");

    const l5 = splitter.next().?;
    var s5 = std.mem.tokenizeAny(u8, l5, " ");

    var total: u64 = 0;

    while (s1.peek() != null){
        const c1 = std.fmt.parseInt(u64, s1.next().?, 10) catch 0;
        const c2 = std.fmt.parseInt(u64, s2.next().?, 10) catch 0;
        const c3 = std.fmt.parseInt(u64, s3.next().?, 10) catch 0;
        const c4 = std.fmt.parseInt(u64, s4.next().?, 10) catch 0;
        const c5 = s5.next().?;

        switch (c5[0]) {
            '+' => {total = total + c1 + c2 + c3 + c4;},
            '*' => {total = total + (c1 * c2 * c3 * c4);},
            else => {},
        }
    }

    std.debug.print("{d}\n", .{total});
}
