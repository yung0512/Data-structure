var sortColors = function (nums) {
  let colorArray = [0, 0, 0];

  nums.forEach((color) => {
    colorArray[color]++;
  });

  let numsIndex = 0;
  colorArray.forEach((count, index) => {
    for (let c = count; c > 0; c--) {
      nums[numsIndex] = index;
      numsIndex++;
    }
  });
};
