for y in coords_y:
    while stack and stack[-1] > y:
        stack.pop()
        island_count += 1

    if stack and stack[-1] == y:
        stack.pop()
         continue
    
    if y > 0:
        if not stack or stack[-1] < y:
            stack.append(y)
