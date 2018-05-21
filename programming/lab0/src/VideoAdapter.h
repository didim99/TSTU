#ifndef _VIDEOADAPTER_H_
#define _VIDEOADAPTER_H_ 1

#include <cstring>
#include <inttypes.h>

class VideoAdapter {
public:
  VideoAdapter() {
    vendor = NULL;
    model = NULL;
    GPUVendor = NULL;
    GPUModel = NULL;
  }

  ~VideoAdapter() {
    if (vendor) delete[] vendor;
    if (model) delete[] model;
    if (GPUVendor) delete[] GPUVendor;
    if (GPUModel) delete[] GPUModel;
  }

  void setId(uint32_t id) { this->id = id; }
  void setVendor(const char *vendor) { storeStrField(vendor, &(this->vendor)); }
  void setModel(const char *model) { storeStrField(model, &(this->model)); }
  void setGPUVendor(const char *GPUVendor) { storeStrField(GPUVendor, &(this->GPUVendor)); }
  void setGPUModel(const char *GPUModel) { storeStrField(GPUModel, &(this->GPUModel)); }
  void setVRAMSize(uint32_t VRAMSize) { this->VRAMSize = VRAMSize; }
  void setPrice(uint32_t price) { this->price = price; }

  uint32_t getId() { return this->id; }
  char *getVendor() { return this->vendor; }
  char *getModel() { return this->model; }
  char *getGPUVendor() { return this->GPUVendor; }
  char *getGPUModel() { return this->GPUModel; }
  uint32_t getVRAMSize() { return this->VRAMSize; }
  uint32_t getPrice() { return this->price; }
private:
  static const int TEXT_FIELD_LEN = 50;

  uint32_t id;
  char *vendor;
  char *model;
  char *GPUVendor;
  char *GPUModel;
  uint32_t VRAMSize;
  uint32_t price;

  void storeStrField(const char *in, char **field) {
    if (!*field) *field = new char[TEXT_FIELD_LEN];
    strcpy(*field, in);
  }
};

#endif /* _VIDEOADAPTER_H_ */
