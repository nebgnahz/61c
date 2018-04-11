Warehouse Scale Computing
---

It is all about scaling!

- 1.01^365 = 37.8
- 0.99^365 = 0.025

---

#### Amdahl's Law

1) You are going to train an image classifier on a training set of 50,000 images
using a WSC of more than 50,000 servers. You notice that 99% of the execution
can be parallelized. What is the speedup?

- Before: 50,000 * t
- After: ((99% * t) / 50000 + 1% * t) * 50000
- Speeup: t / ((99% * t) / 50000 + 1% * t) = 99.8x

#### Failure

1) A WSC has 55,000 servers, and each server has four disks whose annual failure
rate is 4%. How many disks will fail per hour?

- Total failures: (55,000 * 4 * 0.04)
- Total hours: 365 * 24
- 1 disk per hour

2) What is the availability of the system if it does not tolerate the failure?
Assume that the time to repair a disk is 30 minutes.

"if it does not tolerate the failure"

Availability: 1 hour available + 0.5 repair => 1 / 1.5, 66.67%

#### Power

Power Usage Effectiveness (PUE) = (Total Building Power) / (IT Equipment Power)

Sources speculate Google has over 1 million servers. Assume each of the 1
million servers draw an average of 200W, the PUE is 1.5, and that Google pays an
average of 6 cents per kilowatt-hour for datacenter electricity.

1) Estimate Google’s annual power bill for its datacenters.

365 * 24 * 0.200 kW * 1 million * 1.5 * 6 cent/kW = 157.68 million USD

2) What if PUE is 1.25 for 50,000?

- New: 365 * 24 * 0.200 kW * 50,000 * (1.5 - 1.25) * 6 cent/kW = 1.314 million USD

---

#### MapReduce

Technique: find the proper key (intermediate index), walk backwards

Bring two decks of poker cards!

map(Card card):
    emit(card.color, card)

reduce(String color, Iterable<Card> cards):
    sorted_cards = cards.sort()
    emit(card.color, sorted_card)


----

#### Spark

