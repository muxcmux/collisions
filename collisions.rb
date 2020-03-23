points = [0, 0, 0, 0, 0].sort
diameter = 5

maxHeight = 100
minHeight = 0

resolved = false

attempts = 0

while (!resolved) do
  attempts += 1

  collision = false

  for i in 0..points.length - 1 do
    for j in 0..points.length - 1 do
      if (i != j)
        diff = (points[i] - points[j]).abs
        if diff < diameter
          collision = true
          offset = ((diameter - diff).abs / 2.0).ceil
          points[i] += offset
          points[j] -= offset
        end
      end
    end
  end

  # if (points.first < minHeight)
  #   collision = true
  #   points[0] = minHeight
  # end
  #
  # if (points.last > maxHeight)
  #   collision = true
  #   points[points.length - 1] = maxHeight
  # end

  resolved = !collision

  abort "Failed after #{attempts} attempts" if attempts > 1000

end

puts "Solved in #{attempts} attempts: #{points}"