define i32 @main() {
%r0 = add i32 0, 3
%r1 = add i32 0, 4
%r2 = add i32 0, 5
%r3 = mul i32 %r1, %r2
%r4 = add i32 0, 2
%r5 = udiv i32 %r3, %r4
%r6 = add i32 %r0, %r5
%r7 = internal constant [7 x i8] c"CHAINE\00"
%r8 = add i32 0, 1
ret i32 0
}