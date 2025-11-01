from enum import Enum
from abc import ABC, abstractmethod

class VehicleType(Enum):
    CAR=1
    BIKE=2
    TRUCK=3

class Vehicle(ABC):
    def __init__(self,license_plate:str,vehicle_type:VehicleType):

        self.license_plate=license_plate
        self.vehicle_type=vehicle_type
class Car(Vehicle):
    def __init__(self,license_plate:str):
        super().__init__(license_plate,VehicleType.CAR)
class ParkingSpot:
    def __init__(self,spot_id:int,vehicle_type:VehicleType,is_occupied:bool=False):
        self.spot_id=spot_id
        self.vehicle_type=vehicle_type
        self.is_occupied=is_occupied
        self.vehicle=None
    def park_vehicle(self,vehicle:Vehicle):
        if self.is_occupied or vehicle.vehicle_type!=self.vehicle_type:
            return False
        self.vehicle=vehicle
        self.is_occupied=True
        return True
    
class ParkingFloor:
    def __init__(self,floor_id:int,spots:list[ParkingSpot]):
        self.floor_id=floor_id
        self.spots=spots
class ParkingLot:
    def __init__(self):
        self.floors=[]
        self.tickets={}
    def add_floor(self,floor:ParkingFloor):
        self.floors.append(floor)
    def park_vehicle(self,vehicle:Vehicle  )->str:
        for floor in self.floors:
            for spot in floor.spots:
                if spot.park_vehicle(vehicle):
                    ticket_id=f"{floor.floor_id}-{spot.spot_id}"
                    self.tickets[ticket_id]=spot
                    return ticket_id
        return "Parking lot is full"
if __name__=="__main__":
    lot=ParkingLot()
    floor1=ParkingFloor(1,[ParkingSpot(i,VehicleType.CAR) for i in range(1,11)])
    lot.add_floor(floor1)
    car1=Car("KA-01-HH-1234")
    ticket_id=lot.park_vehicle(car1)
    print(ticket_id)