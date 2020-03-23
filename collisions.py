def space_balls(points, min_y, max_y, dia):
    if len(points) == 1:
        return points
    if len(points) * dia > abs(min_y - max_y):
        print "No solution: ", points
        return False
    points.sort()
    done = False
    iterations = 0
    while not done:
        iterations += 1
        error = False
        if points[0] < min_y:
            points[0] += 1
        if points[-1] > max_y:
            points[-1] -= 1
        for idx, p2 in enumerate(points[1:]):
            p1 = points[idx]
            diff = abs(p1 - p2)
            if diff < dia:
                #print "collision. p1: {}\t p2: {}\t diff: {}\t points: {}".format(p1, p2, diff, points)
                points[idx] -= 1
                points[idx+1] += 1
                error = True
        done = not error
    #print points
    return (iterations, points)

print space_balls([0,0,0,0,0], 0, 30, 5)